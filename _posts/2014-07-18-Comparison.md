---
layout: post
title: "Exploration of Distributed Hash Algorithms and Overlay Networks: Comparison"
date: 2014-07-18 15:39:00
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

Criteria | Results
:-- | :--:
**Nodes**: State | Has "Finger Tables", each node maintains information about `O(log N)` other nodes. + successor table of size `O(log N)` (Total = O(2 log N))
**Nodes**: Joining Cost | `O(log^2 N)` messages are required.
**Nodes**: Leaving Cost | `O(log^2 N)` messages are required.
**RP**: Node Lookup | `O(log N)` messages are required.  
**RP**: Key Lookup | `O(log N)` messages are required. 
**RP**: Deterministic | Yes a query will always return a value, or a definitive failure (The key does **not** exist in the system).
Failure Resistant | With a successor list of length `r = O(log N)` in a network that is initially stable, and then every node fails with probability of `1/2`, then the expected time to execute *find_successor* in the failed network is `O(log N)`.† 
**Overall Performance** | Node/Key Lookup (in presence of high failure rate) still remains `O(log N)`.

† *taken from the [original paper](http://pdos.csail.mit.edu/papers/chord:sigcomm01/chord_sigcomm.pdf)*

###Koorde

Criteria | Results
:-- | :--:
**Nodes**: State | Each node has to maintain information for 3 nodes (pointers): (its successor , first node that precedes `2m` (pointer to the start of the de Bruijn graph) and its predecessor).(State = `O(1)`) *(In the non-constant degree variation nodes maintain information for k nodes.)*
**Nodes**: Joining Cost | `O(log^2 N)` messages are required. (As with Chord.)
**Nodes**: Leaving Cost | `O(log^2 N)` messages are required. (As with Chord.)
**RP**: Node Lookup | `O(log N)` messages are required if using a degree of 2. Can be optimized to `O(log N/ log log N)` using a degree of `O(log N).`
**RP**: Key Lookup | `O(log N)` messages are required if using a degree of 2. Can be optimized to `O(log N/ log log N)` using a degree of `O(log N).`
**RP**: Deterministic | Yes a query will always return a value, or a definitive failure (The key does **not** exist in the system).
Failure Resistant | With a pointer to a list of successors of length `θ(log N)` and a pointer to two lists (one consisting of `θ(log N)` nodes positioned after `k` and a similar list for nodes position before `k`) and then every node fails with probability of `1/2`, any lookup can be execute in the failed network with `O(log N/ log log N)` messages. 
**Overall Performance** | Node/Key Lookup (in presence of high failure rate) can be up to `O(log N/ log log N)`.

###Pastry

Criteria | Results
:-- | :--:
**Nodes**: State | Each node has to maintain three tables: Leaf Set (L), Routing Table (`O(log N)`) and the Neighborhood Set (M). Total = L + M + `O(log N)`. †
**Nodes**: Joining Cost | `O(log<sub>2<sup>b</sup></sub> N)` messages are required. (As with Chord.)
**Nodes**: Leaving Cost | `O(log^2 N)` messages are required. (As with Chord.)
**RP**: Node Lookup | `O(log N)` messages are required.
**RP**: Key Lookup | `O(log N)` messages are required.
**RP**: Deterministic | Yes a query will always return a value, or a definitive failure (The key does **not** exist in the system).
Failure Resistant | With a pointer to a list of successors of length `θ(log N)` and a pointer to two lists (one consisting of `θ(log N)` nodes positioned after `k` and a similar list for nodes position before `k`) and then every node fails with probability of `1/2`, any lookup can be execute in the failed network with `O(log N/ log log N)` messages. 
**Overall Performance** | Node/Key Lookup (in presence of high failure rate) can be up to `O(log N/ log log N)`.

† *`b` correspond the exponent to the digit base representation (`2^b`); and L = M = `2^b or 2 * 2^b`*