Installing docker on Fedora 32
##############################

:date: 2020-06-12
:category: Technology
:slug: docker-configuration
:summary: How to configure docker on a system running Fedora 32

As of the time of writing the docker repos DO NOT have an entry for Fedora 32

.. raw:: html

    <br />

Recently, I have began learning docker. However upon attempting to install it, I ran into a few issues which resulted in me using an ubuntu server virtual machine, which was less than ideal
for what I was attempting. Below I will document what I did and how I solved the issues that I had ran into.

.. raw:: html

    <br />

First off before we start installing anything new it's best to run an update first.

.. code-block:: bash

    sudo dnf -y update
    #safer to restart your system after
    sudo shutdown -r now

Next we want to add the docker repo, so that we can install the packages we want

.. code-block:: bash

    sudo dnf config-manager \
    --add-repo \
    https://download.docker.com/linux/fedora/docker-ce.repo

However, if we try to install docker-ce now, we get 404, as the repository does not contain entries for fedora 32 yet, we can opt to use the fedora 31
repos through the following command.

.. code-block:: bash

    sudo sed -i 's/$releasever/31/g' /etc/yum.repos.d/docker-ce.repo

If you are not familiar with sed, all this does is goes through the entry yum/dnf has for the docker repo and replaces 32 with 31 -> hence we actually install packages from the fedora 31 repos.
Now we can install packages that we need from the docker repo, for instance.

.. code-block:: bash

    sudo dnf install docker-ce

And we also want to enable the docker service, we can do this without rebooting using the now arguement. We additionally may want to add ourselves to the group docker so we can use docker commands without sudo

.. code-block:: bash

    sudo systemctl enable --now docker
    sudo usermod -aG docker $(whoami)

However, if we try to create a new container with some arbitrary image, like so, we may get a final error regarding cgroups, Since fedora 31, the default setting is for cgroup V2 to before
enabled by default. (cgroups is a feature implemented in the kernel that allows for the isolation of resources to a collection of processes, clearly this is useful when utilising containers)#
sadly this isnt supported by docker yet (at the time of writing).

.. code-block:: bash

    docker run --rm hello-world

    # probably some image pull stuff here

    docker: Error response from daemon: cgroups: cannot found cgroup mount destination: unknown.

In order to fix this we can revert back to cgroups V1 on the next reboot by providing an arguement to the kernel.

.. code-block:: bash

    sudo dnf install grubby
    sudo grubby --update-kernel=ALL --args=”systemd.unified_cgroup_hierarchy=0"

Now after all that we should be able to get the hello world image to work with

.. code-block:: bash

    docker run --rm hello-world
    # this should work
    
