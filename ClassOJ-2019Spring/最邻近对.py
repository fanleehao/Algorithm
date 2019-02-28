# -*- coding: utf-8 -*-
"""
Created on Sat Feb 16 10:27:11 2019

@author: hodor
"""
import math
def dis(d1,d2):
    return math.sqrt((d1[0]-d2[0])*(d1[0]-d2[0])+(d1[1]-d2[1])*(d1[1]-d2[1]))

def findmin(l,r):
    if l==r:
        return 100100.0,[]
    if l==r-1:
        return dis(data[l],data[r]),[[data[l],data[r]]]
    dis1,data1=findmin(l,int((l+r)/2))
    dis2,data2=findmin(int((l+r)/2)+1,r)
    midx=data[int((l+r)/2)][0]
    minDis=100100.0
    if dis1<dis2:
        minDis=dis1
        res=data1
    elif dis1==dis2:
        minDis=dis2
        res=data1+data2
    else:
        minDis=dis2
        res=data2
    temp=[]
    for i in range(l,r+1):
        if abs(data[i][0]-midx)<=minDis:
            temp.append(data[i])
    for i in range(len(temp)):
        for j in range(i+1,len(temp)):
            if temp[i][1]>temp[j][1]:
                ttemp=temp[i]
                temp[i]=temp[j]
                temp[j]=ttemp
    for i in range(0,len(temp)-1):
        for j in range(i+1,len(temp)):
            if j==i+7:
                break
            tmp=dis(temp[i],temp[j])
            if tmp<minDis:
                minDis=tmp
                res=[[temp[i],temp[j]]]
            if tmp==minDis and [temp[i],temp[j]] not in res and [temp[j],temp[i]] not in res:
                res.append([temp[i],temp[j]])
    return minDis,res


t=int(input())
for eacht in range(t):
    data=input().split(",")
    for i in range(len(data)):
        data[i]=list(map(float,data[i].split()))
    for i in range(len(data)):
        for j in range(i+1,len(data)):
            if data[i][0]>data[j][0]:
                tempp=data[i]
                data[i]=data[j]
                data[j]=tempp
    l=0
    r=len(data)-1
    minDis,points=findmin(l,r)
    for i in range(len(points)):
        if points[i][0][0]>points[i][1][0]:
            tempp=points[i][0]
            points[i][0]=points[i][1]
            points[i][1]=tempp
        elif points[i][0][0]==points[i][1][0] and points[i][0][1]>points[i][1][1]:
            tempp=points[i][0]
            points[i][0]=points[i][1]
            points[i][1]=tempp
    
    for i in range(len(points)):
        for j in range(i+1,len(points)):
            if points[i][0][0]>points[j][0][0]:
                tempp=points[i]
                points[i]=points[j]
                points[j]=tempp
            elif points[i][0][0]==points[j][0][0] and points[i][0][1]>points[j][0][1]:
                tempp=points[i]
                points[i]=points[j]
                points[j]=tempp
            elif points[i][0][0]==points[j][0][0] and points[i][0][1]==points[j][0][1] and points[i][1][0]>points[j][1][0]:
                tempp=points[i]
                points[i]=points[j]
                points[j]=tempp
            elif points[i][0][0]==points[j][0][0] and points[i][0][1]==points[j][0][1] and points[i][1][0]==points[j][1][0] and points[i][1][1]>points[j][1][1]:
                tempp=points[i]
                points[i]=points[j]
                points[j]=tempp  
    for i in range(len(points)):
        if points[i][0][0]==float(int(points[i][0][0])):
            points[i][0][0]=int(points[i][0][0])
        print(points[i][0][0],end=" ")
        if points[i][0][1]==float(int(points[i][0][1])):
            points[i][0][1]=int(points[i][0][1])
        print(points[i][0][1],end=",")
        if points[i][1][0]==float(int(points[i][1][0])):
            points[i][1][0]=int(points[i][1][0])
        print(points[i][1][0],end=" ")
        if points[i][1][1]==float(int(points[i][1][1])):
            points[i][1][1]=int(points[i][1][1])
        if i==len(points)-1:
            print(points[i][1][1])
        else:
            print(points[i][1][1],end=",")
            
            
            
                
                
                
                
                
    
        