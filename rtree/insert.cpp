Algorithm Insert(TypeEntry E, TypeNode RN)

Traverse the tree from root RN to the appropriate leaf. At each level, select the node, L, whose MBR will require the minimum area enlargement to cover E.mbr
In case of ties, select the nose whose MBR has the minimum area
if the selected leaf L can accommodate E
	Insert E into L
	Update all MBRs in the path from the root to L, 
	so that all of them cover E.mbr
else // L is already full
	Add E into L, then split L into L1 and L2
	Update the MBRs of node that are in the path from root to L, so as to covers L1 and accommodate L2
	Perform splits as the upper levels if necessary
	In case the root has to be split, create new root
	Increase the height of the tree by one
endif