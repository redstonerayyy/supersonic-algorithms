import numpy as np
import matplotlib.pyplot as plt


data = [
    # data comparison
    [
        [
            "go quicksort(7 Mil.)",
            "lua quicksort",
            "lua table.sort",
            "java Collection.sort()",
            "javascript quicksort",
            "java quicksort",
            "julia custom/built-in",
            "javascript standard sort"
        ],
        [
            0.919,
            11.528,
            11.035,
            5.016,
            3.167,
            2.828,
            1.374,
            1.159
        ],
        "Vergleich von Sprachen"
    ],
    # cpp, radixsort
    [
        [
            "C++ radixsort",
            "ctypes cast to c-like array",
            "C++ quicksort",
            "C quicksort with ctypes",
            "C++ std::sort",
            "C++ terdiman radixsort",
            "C++ terdiman AVX2"
        ],
        [
            2.269,
            2.058,
            1.051,
            1.035,
            0.909,
            0.244,
            0.240,
        ],
        "C++ Implementierungen"
    ],
    # slow
    [
        [
            "quicksort numpy array",
            "cython quicksort",
            "quicksort python list",
            "cython quicksort all optimizations",
            "cython quicksort with types"
        ],
        [
            72.231,
            52.808,
            40.493,
            14.717,
            14.403
        ],
        "Langsame Python Implementierungen"
    ],
    # numba, numpy
    [
        [
            "quicksort numba numba.typed list",
            "list.sort() python list",
            "quicksort numba numpy array",
            "list.sort() numpy array"
        ],
        [
            9.744,
            5.314,
            1.805,
            0.894,
        ],
        "Schnelle Python Implementierungen"
    ],
    # list generation
    [
        [
            "comprehension to numba.typed list",
            "list comprehension",
            "list comprehension numba",
            "numpy.random.randint numba",
            "numpy.random.randint",
        ],
        [
            26.849,
            9.307,
            1.148,
            0.401,
            0.051
        ],
        "Generierung von Zufallszahlen"
    ]
]

# set font size
plt.rc('font', size=12)

for i in data:

    # create figure
    fig = plt.figure(figsize = (10, 5))
    # create plot
    plt.bar(i[0], i[1], color ='blue', width = 0.4)
    # name the axis and give title
    plt.xlabel("Variations")
    plt.ylabel("Zeit in Sekunden für 10 Millionen Elemente")
    plt.title(i[2])
    # show
    plt.show()