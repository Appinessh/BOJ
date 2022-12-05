n,m=map(int,input().split())
arra=[]

for j in range(n):
    arra.append(list(input()))
a= min(n,m)
size_max=1;
for i in range(a,1,-1):
    for j in range(n-i+1) :
        for k in range(m-i+1):
            if arra[j][k]==arra[j+i-1][k] and arra[j][k]==arra[j][k+i-1] and arra[j][k]==arra[j+i-1][k+i-1] :
                size_max=i 
            if size_max !=1:
                break;
        if size_max !=1:
           break;
    if size_max !=1:
        break;
print(size_max**2)
