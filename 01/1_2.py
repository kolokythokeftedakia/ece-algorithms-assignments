import math

def FREQUENCY(C,P):
	if len(P)>0:
		l=len(P)
		mid=int(math.ceil((l-1)/2))
		if l>1:
			left=P[0:mid]
			FREQUENCY(C,left)
			right=P[mid:l]
			FREQUENCY(C,right)
		elif l==1:
			C[P[0]]+=1
	else:
		print("ERROR")
pass

C={
	"C8": 0,
	"C3": 0,
	"C1": 0,
	"C9": 0,
	"C128": 0,
	"C0": 0
}

PLACE=["C9","C128"]
# PLACE=["C9","C128","C9"]
# PLACE=["C9","C128","C0","C1"]

# MAIN
POP_CAND=[]
FREQUENCY(C, PLACE)

for candidate in C.keys():
	if C[candidate]>=math.ceil(len(PLACE)/2):
		POP_CAND.append(candidate)

print(POP_CAND)