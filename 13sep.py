
class Solution:
    def largestOverlap(self, A, B):
        
        
        # Collect coordinates of 1s in given matrix
        def collectOnes( matrix ):
            
            coordinate = set()
            
            for y, row in enumerate(matrix):
                for x, value in enumerate(row):
                    if value == 1:
                        coordinate.add( (x, y) )
                        
            return coordinate
        
        # ---------------------------------------
        
        OnesInA = collectOnes( A )
        OnesInB = collectOnes( B )
        
        
        # key: shifting vector
        # value: occurrence of shifting vector
        vectorOccurrence = defaultdict(int)
        
        for Ax, Ay in OnesInA:
            for Bx, By in OnesInB:
                
                # Compute shifting vector between A's 1 and B's 1
                vector = (Ax-Bx, Ay-By)
                
                # Add occureence for common shifting vector
                vectorOccurrence[ vector ] += 1
        
        # Max occurrence of shifting vector is the answer
        # If no shifting vector, then no overlapping at all, return 0
        return max( vectorOccurrence.values() or [0] )
        