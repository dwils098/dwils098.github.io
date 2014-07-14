---
layout: post
title: ZeroMQ A first impression
---

As an exploration exercise, I wished to utilize a [Publish-Subscribe Architecture](http://en.wikipedia.org/wiki/Publish%E2%80%93subscribe_pattern) within my BBB Development cluster in order to provide asynchronous messaging capabilities. Thus after a bit of research on the Inter-Webs, I settled on using [ZeroMQ](http://zeromq.org/) which seemed the most flexible and lightweight message queue framework currently available. 

---
*It's sockets on steroids. It's like mailboxes with routing. It's fast! [...] Things just become simpler. Complexity goes away. It opens the mind.*

And let's be honest this is pretty catchy! So I'm in!

---

## Zguide: notes and thoughts

These are just my thoughts on the examples and some notes to ease my comprehension as I walkthrough the guide various chapters. Please note that I will be using the Python binding to use the 0mq library, and thus will work through the examples in Python language.

###Chapter 1
####First Example: Request-Reply Pattern 

The first example in the guide consist of a simple Request-Reply architecture composed of a client and a server. The client emits a request to the server and the server answers with a reply. The extent of the exemple is fairly limited, with hard-coded values, but provide a simple hands-on first glimpse at data sending and receiving in 0mq.

####Second Example: One-Way Out Distribution Pattern

The second example, consist of a server pushing a set of updates to a series clients. More precisely a weather information server that pushes out randomly generated weather information updates and a consumer (client) that consume these updates based on their ZIP code. Thus, the pub-sub pattern is introduced.

####Third Example: 