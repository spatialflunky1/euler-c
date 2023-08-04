from math import sqrt

def sieve(num):
    # output: all prime nums 2 through num
    arr = {} 
    for i in range(2,num+1):
        arr[i] = True
    for i in range(2,int(sqrt(num))+1):
        if arr[i]:
            j = i*i
            while j <= num:
                arr[j] = False
                j += i

    for i in range(2,num+1):
        if (arr[i]):
            print(i)
    #2,num+1   1,num   0,num-1
    # num-2 = last index



if __name__ == "__main__":
    sieve(13)
