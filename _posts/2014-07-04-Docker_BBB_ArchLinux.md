---
layout: post
title: Docker on BeagleBone Black using ArchLinux
---

With the recent interest in containers, more specifically with [Docker](http://www.docker.com), I decided to install it on a 3 [BeagleBone Black](http://beagleboard.org/black) and create a Linux Development cluster. The motivation behind this is to be able to deploy Python applications in a clustered environment, and as mentioned above Docker seemed to fit the bill.

#Out of the box
The BBB runs a version of Linux called [Ångström](http://www.angstrom-distribution.org/) which was created in the scope of providing a stable user-friendly distribution with a focus on embedded devices.

##First Attempt
My initial thoughts were that Docker would run on *any* Linux platform, and I was wrong. Therefore, my first attempt consisted of trying to install Docker on the BBB as-is, but to no avail, the Docker package is not part of the [opkg](http://en.wikipedia.org/wiki/Opkg) [list of packages](http://feeds.angstrom-distribution.org/feeds/unstable/ipk/glibc/armv7a/).
 