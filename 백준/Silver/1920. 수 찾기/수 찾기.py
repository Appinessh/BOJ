N=int(input())
A=list(map(int,input().split()))
M=int(input())
B=list(map(int,input().split()))
A.sort()
for num in B:
    start=0
    end=N-1
    mid=(start+end)//2
    while True:
        if A[mid]==num:
            print(1)
            break
        elif start>=end:
            print(0)
            break
        elif A[mid]>num:
            end=mid-1
            mid=(end+start)//2
        else :
            start=mid+1
            mid=(end+start)//2
