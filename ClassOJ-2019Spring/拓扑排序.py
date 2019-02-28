# -*- coding: utf-8 -*-
"""
Created on Tue Jan 29 09:32:36 2019

@author: hodor
"""
def count(nodes,edge):
    res=0
    if len(nodes)==1:return 1
    for n in nodes:
        flag=0
        for e in edge:
            start,end=e.split()
            if end == n:
                flag=1
                break
        if flag==0:
            nodes1=set(nodes)
            nodes1.remove(n)
            edge1=[]
            for e in edge:
                start,end=e.split()
                if start!=n:
                    edge1.append(e)
            res+=count(nodes1,edge1)
    return res
        

t = int(input())
for eacht in range(t):    
    edge=input().split(",")
    nodes=set()
    for e in edge:
        start,end=e.split()
        nodes.add(start)
        nodes.add(end)
    res=count(nodes,edge)
    print(res)
