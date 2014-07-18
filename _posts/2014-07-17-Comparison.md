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
	
2. Routing Protocol:
	
	i. Node Lookup Cost/Key Lookup Cost.
	
	ii. Deterministic versus Non-Deterministic.

3. Failure Resistant.

###Chord


dog | bird | cat
:-- | :--: | --:
foo | foo  | foo
bar | bar  | bar
baz | baz  | baz