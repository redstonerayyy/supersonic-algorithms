
// https://stackoverflow.com/questions/504103/how-do-i-write-a-correct-micro-benchmark-in-java maybe?

import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

class Quicksort {
    public static void main(String[] args) {
        long tenmillion = 10000000;
        int maximum = Integer.MAX_VALUE;
        // custom quicksort
        List<Integer> liste = new Random().ints(tenmillion, 0, maximum)
                .boxed()
                .collect(Collectors.toList());

        // liste.forEach(System.out::print);
        long start = System.nanoTime();
        quicksort(liste, 0, liste.size() - 1);
        long end = System.nanoTime();
        System.out.println((end - start) / 1000000);
        // liste.forEach(System.out::print);

        // std sort
        List<Integer> liste_zwei = new Random().ints(tenmillion, 0, maximum)
                .boxed()
                .collect(Collectors.toList());

        long start_zwei = System.nanoTime();
        Collections.sort(liste_zwei);
        long end_zwei = System.nanoTime();
        System.out.println((end_zwei - start_zwei) / 1000000);
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