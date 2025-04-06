Algorithm RangeSearch (TypeNode RN, TypeRegion Q)

// Answer are stored in the set A

if RN is not a leaf node
	examine each entry e of RN to find those e.mbr that intersect Q
	foreach such entry e call RangeSeach(e.ptr, Q)
else // RN is a leaf node
	examine all entries e and find those for which e.mbr intersects Q
	add these entries to the answer set A
endif