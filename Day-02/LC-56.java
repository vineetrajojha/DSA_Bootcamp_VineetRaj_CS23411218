
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {

    public int[][] merge(int[][] intervals) {

        // Step 1: sort by starting time
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        List<int[]> result = new ArrayList<>();

        // Step 2: add first interval
        int[] current = intervals[0];
        result.add(current);

        // Step 3: merge intervals
        for (int i = 1; i < intervals.length; i++) {
            int[] next = intervals[i];

            if (next[0] <= current[1]) {
                // overlap → merge
                current[1] = Math.max(current[1], next[1]);
            } else {
                // no overlap
                current = next;
                result.add(current);
            }
        }

        return result.toArray(new int[result.size()][]);
    }
}
