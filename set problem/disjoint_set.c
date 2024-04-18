#include <stdlib.h>
#include <stdio.h>


int find(int* parent, int i)
{
    //재귀적으로 대표자 탐색
    //목표가 자기 자신일 때 return
	if (parent[i] == i) {
		return i;
	}
	else {
		return find(parent[i]);
	}
}

int find_compression(int * parent, int i) 
{
    //경로 압축 버전
    if (parent[i] == i) {
        return i;
    }
    else { 
        int result = find(parent, parent[i]);
        parent[i] = result;
        return result;
     }
}

void do_union_standard(int i, int j) {
 
    // Find the representatives
    // (or the root nodes) for the set
    // that includes i
    int irep = this.Find(i),
 
    // And do the same for the set
    // that includes j
    int jrep = this.Find(j);

    this.Parent[irep] = jrep;
}

void union_rank(int i, int j) {
 
    // Find the representatives (or the root nodes)
    // for the set that includes i
    int irep = this.find(i);
 
    // And do the same for the set that includes j
    int jrep = this.Find(j);
 
    // Elements are in same set, no need to
    // unite anything.
    if (irep == jrep)
        return;
     
      // Get the rank of i’s tree
    irank = Rank[irep],
 
    // Get the rank of j’s tree
    jrank = Rank[jrep];
 
    // If i’s rank is less than j’s rank
    if (irank < jrank) {
 
        // Then move i under j
        this.parent[irep] = jrep;
    }
 
    // Else if j’s rank is less than i’s rank
    else if (jrank < irank) {
 
        // Then move j under i
        this.Parent[jrep] = irep;
    }
 
    // Else if their ranks are the same
    else {
 
        // Then move i under j (doesn’t matter
        // which one goes where)
        this.Parent[irep] = jrep;
 
        // And increment the result tree’s
        // rank by 1
        Rank[jrep]++;
    }
}

void union_size(int i, int j) {
 
    // Find the representatives (or the root nodes)
    // for the set that includes i
    int irep = find(i);
 
    // And do the same for the set that includes j
    int jrep = find(j);
 
    // Elements are in the same set, no need to
    // unite anything.
    if (irep == jrep)
        return;
 
    // Get the size of i’s tree
    int isize = Size[irep];
 
    // Get the size of j’s tree
    int jsize = Size[jrep];
 
    // If i’s size is less than j’s size
    if (isize < jsize) {
 
        // Then move i under j
        Parent[irep] = jrep;
 
        // Increment j's size by i's size
        Size[jrep] += Size[irep];
    }
 
    // Else if j’s size is less than i’s size
    else {
 
        // Then move j under i
        Parent[jrep] = irep;
 
        // Increment i's size by j's size
        Size[irep] += Size[jrep];
    }
}