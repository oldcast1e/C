#include<stdio.h>
int main(){
int i,en[26]={};char arr[90];fgets(arr,90,stdin);for(i=0;i<strlen(arr);i++)if('a'<=arr[i]&&arr[i]<='z')en[arr[i]-'a']+=1;for(i=0;i<26;i++)printf("%c:%d\n",'a'+i,en[i]);} 
/*
a:0
b:0
c:0
d:1
e:0
f:0
g:1
h:1
i:0
j:0
k:0
l:0
m:1
n:0
o:2
p:0
q:0
r:0
s:0
t:0
u:0
v:0
w:0
x:0
y:1
z:0 
26
*/