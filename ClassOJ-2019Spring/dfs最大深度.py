# -*- coding: utf-8 -*-
"""
Created on Mon Jan 28 10:16:54 2019

@author: hodor
"""


def dfs(start,depth):
    if depth>maxdepth[0]:
        maxdepth[0]=depth
    nodeset=G[node.index(start)]
    for n in nodeset:
        if n in flag: continue
        flag.add(n)
        dfs(n,depth+1)
        flag.remove(n)


t=int(input())
for eacht in range(t):
    count,start=input().split()
    node=input().split()
    G=[]
    maxdepth=[0]
    for i in range(len(node)):
        line=list(map(int,input().split()[1:]))
        nodeset=set()
        for j in range(len(node)):
            if line[j]==1:
                nodeset.add(node[j])
        G.append(nodeset)
    flag=set()
    flag.add(start)
    dfs(start,1)
    print(maxdepth[0])
    
    
        