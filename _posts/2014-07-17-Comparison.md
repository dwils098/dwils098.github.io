---
layout: post
title: "Exploration of Distributed Hash Algorithms and Overlay Networks: Comparison"
date: 2014-07-17 15:39:00
---

In this post we will compare the 4 different DHT algorithms surveyed on various aspects and try to come up with the pros and cons of each algorithms. But first let's look on what basis we will compare them, in other words which features and/or characteristics are evaluated.

##Evaluation Criteria
These represents the **main** evaluation criteria:

1. Nodes:
    
	i. State (space (and meta-data) required for each participating nodes).
	
	ii. Joining Cost.
	
	iii. Leaving Cost.
	
2. Routing Protocol:
	
	i. Node Lookup Cost/Key Lookup Cost.
	
	ii. Deterministic versus Non-Deterministic.

3. Failure Resistant.

4. Overall Performance.

Let's look at each of them separately for each DHT, then we will present a summary table.

###Chord

Criteria | Result 
:-- | :--:
**Nodes**: State | Has "Finger Tables", each node maintains information about `O(log N)` other nodes.
**Nodes**: Joining Cost | `O(log^2 N)` messages are required.
**Nodes**: Leaving Cost | `O(log^2 N)` messages are required.
**RP**: Node Lookup | `O(log N)` messages are required.  
**RP**: Key Lookup | `O(log N)` messages are required. 
**RP**: Deterministic | Yes a query will always return a value, or a definitive failure (The key does **not** exist in the system).
Failure Resistant | With a successor list of length `r = O(log N)` in a network that is initially stable, and then every node fails with probability of `1/2`, then the expected time to execute *find_successor* in the failed network is `O(log N)`† 
**Overall Performance** | Node/Key Lookup (in presence of high failure rate) still remains `O(log N)`

† *taken from the [original paper](http://pdos.csail.mit.edu/papers/chord:sigcomm01/chord_sigcomm.pdf)*