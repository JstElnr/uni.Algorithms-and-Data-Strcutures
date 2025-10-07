def is_prime(x):
    if x<2:return False
    if x==2:return True
    if x%2==0:return False
    i=3
    while i*i<=x:
        if x%i==0:return False
        i+=2
    return True
n=int(input())
primes=[]
i=2
while len(primes)<600:
    if is_prime(i):primes.append(i)
    i+=1
superprimes=[primes[i-1] for i in primes if i<=len(primes)]
print(superprimes[n-1])