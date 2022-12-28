# Peephole Optimization in Python

See here:

-   https://stackify.com/how-to-optimize-python-code/
-   https://pythonsimplified.com/optimization-in-python-peephole/

Optimization Techniques

-   constant expression evaluation -> immutable types(strings(<= 4096), tuples(<=256), ...), replace list constants with tuples
-   share objects like strings globally in programs and sessions
-   cProfile, time, timeit
-   libraries and pre-compiled and C based functions offer the most performance
-   avoid globals
-   idiomatic code: the complexy of code is often different although they perform the same task so the fastest way should be used (contraty to compiled languages)
-   generators and lazy evaluation e.g. range()/xrange()
-   use numba with JIT
-   C/C++ options e.g. https://wiki.python.org/moin/IntegratingPythonWithOtherLanguages
