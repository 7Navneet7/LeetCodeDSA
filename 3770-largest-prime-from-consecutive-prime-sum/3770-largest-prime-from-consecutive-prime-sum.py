class Solution:
    def isPrime(self,n:int)->bool:
        if n<2:
            return False
        if n%2==0:
            return n==2
        i=3
        while i*i<=n:
            if n%i==0:
                return False
            i+=2
        return True        

    def largestPrime(self, n: int) -> int:
        sum=2
        res=0
        if n>=2:
            res=2
        x=3
        while sum+x<=n:
            if self.isPrime(x):
                sum+=x
                if self.isPrime(sum) and sum<=n:
                    res=sum
            x+=1

        return res
        