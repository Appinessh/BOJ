a = input()
list_alphabet = ['dz=', 'nj', 'lj', 'c=', 's=', 'z=', 'c-', 'd-']
count = 0
while len(a)!=0:
    if a[0:3]==list_alphabet[0]:
        a=a[3:]
        count+=1
    elif a[0:2] in list_alphabet[1:]:
        a=a[2:]
        count+=1
    else:
        a=a[1:]
        count+=1
print(count)