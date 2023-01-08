function hoare_partition(array, start, end) {
    pivot = array[Math.trunc((start + end) / 2)];

    i = start - 1;
    j = end + 1;

    while (true) {
        ++i;
        while (array[i] < pivot) {
            ++i;
        }

        --j;
        while (array[j] > pivot) {
            --j;
        }

        if (i >= j) {
            return j;
        }

        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

function quicksort(array, start, end) {
    if (start >= 0 && end >= 0 && start < end) {
        crossing = hoare_partition(array, start, end);

        quicksort(array, start, crossing);
        quicksort(array, crossing + 1, end);
    }
}

// custom quicksort
let liste = Array(10000000)
    .fill()
    .map(() => Math.floor((4294967295 + 1) * Math.random()));

let start = performance.now();
quicksort(liste, 0, liste.length - 1);
let end = performance.now();

console.log("Quicksort", end - start);

// std sort
let liste_zwei = Array(10000000)
    .fill()
    .map(() => Math.floor((4294967295 + 1) * Math.random()));

let start_zwei = performance.now();
quicksort(liste, 0, liste.length - 1);
let end_zwei = performance.now();

console.log("Standard Sort", end_zwei - start_zwei);
