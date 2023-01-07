
// https://stackoverflow.com/questions/504103/how-do-i-write-a-correct-micro-benchmark-in-java maybe?

import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

class Quicksort {
    public static void main(String[] args) {
        List<Integer> liste = new Random().ints(10000000, 0, Integer.MAX_VALUE)
                .boxed()
                .collect(Collectors.toList());

        long start = System.nanoTime();
        quicksort(liste, 0, liste.size() - 1);
        long end = System.nanoTime();
        System.out.println((end - start) / 1000000);
        // liste.forEach(System.out::println);
    }

    private static int hoare_partition(List<Integer> list, int start, int end) {
        int pivot = list.get((int) ((start + end) / 2));
        int i = start - 1;
        int j = end + 1;
        while (true) {
            i++;
            while (list.get(i) < pivot) {
                i++;
            }
            j--;
            while (list.get(j) > pivot) {
                j--;
            }
            if (i >= j) {
                return j;
            }
            int temp = list.get(i);
            list.set(i, list.get(j));
            list.set(j, temp);
        }
    }

    private static void quicksort(List<Integer> list, int start, int end) {
        if (start >= 0 && end >= 0 && start < end) {
            int crossing = hoare_partition(list, start, end);
            quicksort(list, start, crossing);
            quicksort(list, crossing + 1, end);
        }
    }
}