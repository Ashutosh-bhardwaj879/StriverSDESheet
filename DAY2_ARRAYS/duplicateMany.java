
/*
 * https://www.youtube.com/watch?v=YoPx8sG_a7E
 * Find All Duplicates In An Array
 */
import java.util.*;

class manyDuplicates {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scn.nextInt();
        }
        List<Integer> res = findDuplicates(arr, n);
        if (res.size() == 0) {
            System.out.println("empty");
            scn.close();
            return;
        }
        Collections.sort(res);
        for (int val : res) {
            System.out.print(val + " ");
        }
        scn.close();
    }

    public static List<Integer> findDuplicates(int[] nums, int n) {
        List<Integer> res = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int index = Math.abs(nums[i]) - 1;
            int val = nums[index];

            if (val < 0) {
                res.add(index + 1);
            } else {
                nums[index] *= -1;
            }
        }

        return res;
    }
}