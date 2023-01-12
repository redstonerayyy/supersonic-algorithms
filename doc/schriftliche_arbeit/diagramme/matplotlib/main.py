import numpy as np
import matplotlib.pyplot as plt


data = [
    # data comparison
    [
        [
            "go\n quicksort(7 Mil.)",
            "lua\n quicksort",
            "lua\n table.sort",
            "java\n Collection.sort()",
            "javascript\n quicksort",
            "java\n quicksort",
            "julia\n custom/built-in",
            "javascript\n standard sort"
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
            "C++\n radixsort",
            "ctypes cast\n to c-like array",
            "C++\n quicksort",
            "C quicksort\n with ctypes",
            "C++\n std::sort",
            "C++ terdiman\n radixsort",
            "C++ terdiman\n AVX2"
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
            "quicksort\n numpy array",
            "cython\n quicksort",
            "quicksort\n python list",
            "cython quicksort\n all optimizations",
            "cython quicksort\n with types"
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
            "quicksort numba\n numba.typed list",
            "list.sort()\n python list",
            "quicksort numba\n numpy array",
            "list.sort()\n numpy array"
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
            "comprehension to\n numba.typed list",
            "list\n comprehension",
            "list\n comprehension numba",
            "numpy.random.randint\n numba",
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
plt.rc('font', size=16)
plt.rc('text', usetex=True)

for i in data:

    # create figure
    fig = plt.figure(figsize = (10, 5))
    # create plot
    plt.bar(i[0], i[1], color ='blue', width = 0.4)
    # name the axis and give title
    plt.xlabel(r'\textbf{Variations}')
    plt.ylabel(r'\textbf{Zeit in Sekunden für 10 Millionen Elemente}')
    plt.title(i[2])
    # show
    plt.show()