from math import sqrt

def sieve(num):
    arr = [True for i in range(0,num-1)]
    for i in range(2,int(sqrt(num))+1):
        if arr[i - 2]:
            j = i*i
            while j <= num:
                arr[j - 2] = False
                j += i
    
    temp = 0
    for i in range(0,num-1):  
        if arr[i]:
            temp+=1

    print(temp)

if __name__ == "__main__":
    sieve(104743)

