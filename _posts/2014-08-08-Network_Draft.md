---
layout: post
title: "Network Layer Draft Architecture"
date: 2014-08-08 15:39:00
---

In this post I will draft out a possible network layer architecture for my Volunteer Cloud Computing Project. The underlying infrastructure will be handled by a Node.js implementation of the popular Kademlia (DHT), which will provide the overlay network. For demonstration purposes, this post will cover a proof of concept implementation of the distributed p2p system using the DHT and a customized API to simulate service discovery.

##API

###findService(service_name)

**Description:** ``` A node looks for a given service using this method and retrieves the location of the service provider using the overlay network. ```

**Inputs:** ``` service_name ```

**Returns:** ``` Location of the service (Ip_address), and null if service doesn't exist. ```

###postService(service_name)
**Description:** ``` A node advertises a service that it provides to the other nodes, using the DHT. ```

**Inputs:** ``` service_name ```

**Returns:** ``` Nothing. ```

###requestService(service_name, [args])
**Description:** ``` This methods provides means for a node to request another node's service on a set of given data. ```

**Inputs:** ``` service_name  ```

**Returns:** ``` boolean indicating if the requested service```