class Solution(object):
    def reverse(self, x):
        x=input() 

        numx=len(x)-1 

        if(x!=0):
            for y in range(numx,-1,-1): 
                print(x[y],end="")
        else:
            print(x)
        