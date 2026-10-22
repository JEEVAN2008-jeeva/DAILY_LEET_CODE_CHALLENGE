int cmpFunc(const void* a, const void* b) {
    int **aa=(int**)a, **bb=(int**)b;

    if((*aa)[0]!=(*bb)[0]){ return (*aa)[0]>(*bb)[0]; }
    return (*aa)[1]>(*bb)[1];
}

int maxNumberOfFamilies(
    int n, int** reserved, int reservedSize, int* reservedColSize
) {
    int result=0, mark, i, j;

    /* Sort the reserved seats. */
    qsort(reserved, reservedSize, sizeof(int*), cmpFunc);

    /* Process the reserved seats. */
    for(i=1,j=0; j<reservedSize; ) {
        /* Count empty rows from the last process. */
        if(reserved[j][0]>i){ result+=(reserved[j][0]-i)*2; }

        /* Mark the column in the row. */
        for(i=reserved[j][0],mark=0b1111111111; j<reservedSize; ) {
            if(reserved[j][0]>i){ break; }
            mark&=~(1<<(reserved[j++][1]-1));
        } i++;

        /* Calculate the result. */
        if((mark&0b0111111110)==0b0111111110){ result+=2; continue; }
        if((mark&0b0000011110)==0b0000011110){ result+=1; continue; }
        if((mark&0b0001111000)==0b0001111000){ result+=1; continue; }
        if((mark&0b0111100000)==0b0111100000){ result+=1; continue; }
    }

    /* Count empty rows after the last process. */
    return result+=(n+1-i)*2;
}