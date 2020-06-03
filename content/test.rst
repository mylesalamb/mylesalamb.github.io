Projects for summer
###################

:date: 2020-6-03 17:43
:category: Programming
:slug: projects-for-summer
:authors: myles
:summary: Planned projects for summer / Some ideas

To keep myself busy over summer, I came up with a few ideas for over summer in relation to programming. They are as follows.

* This website: I have wanted to write my own website for a while but i was not much of a fan of github pages + jekyll offering, hence through using pre-commit hooks and branch trickery
  one can use any other static site generator to acheive this. I opted to use Pelican as I like the Jinja templating engine (the same engine used for Django).

* Continuation of "IPoSMS": I also want to explore the idea developed during the "Do you have the guts?" hackathon of 2019, where a mobile browser that operated over SMS was produced.
  The original implementation utilised twilio, that while convenient, was actually quite costly (Our hackathon time expended about £75 in twilio credit over a single weekend).
  Hence I purchased a GPRS shield in order to use a much cheaper pay as you go / contract sim. However this project requires a soldering iron, and due to current affairs I am unlikely
  to be able to borrow one in the near future.

* Turning a VFD display (Customer display pole) into an alarm clock: I began looking into this project a while ago, however sourcing cheap customer display poles is somewhat
  difficult. This is due to it being preferable to obtain a 'newer' model using USB for data transfer. This project intriques me as it is likely that one would need to write
  a kernel module / driver for the display, and a minor application of reverse engineering assuming a vendor driver could be obtained for windows.
