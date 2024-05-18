# BenchSyntaxLab

[![pt-br](https://img.shields.io/badge/lang-pt--br-green
)](https://github.com/Artprozew/BenchSyntaxLab/blob/main/README.pt-br.md)

This is an experimental project that benchmarks the performance of several programming languages I've been actively using and studying lately. It also includes some rather interesting **supersets**, such as Cython (a "C-like" superset of Python).

Not only can you compare the performance of these languages, but you’re also encouraged to explore their **syntax**, **composition**, **building** and other aspects. Feel free to take a look at the source code! 😊

I've been trying to maintain a similar structure for each code while still taking advantage of their unique features, and also ensuring that they will deliver optimal performance in each specific scenario.

---

## Table of Contents

- [BenchSyntaxLab](#benchsyntaxlab)
  - [Table of Contents](#table-of-contents)
  - [Benchmarks](#benchmarks)
    - [PC Specifications](#pc-specifications)
    - [Prime numbers](#prime-numbers)
  - [Compiling and Running](#compiling-and-running)
    - [Recommended](#recommended)
    - [Quick Setup](#quick-setup)
  - [Contributing](#contributing)
    - [Code Styling](#code-styling)
  - [Licensing](#licensing)

---

## Benchmarks

### PC Specifications

> - CPU: AMD Ryzen 5 3600
> - RAM: 2x16GB DDR4 ~2666MHz

### Prime numbers

Test by getting 20,000 primes in 10 runs, using the same code structure and algorithm ("trial division").

| Language      | Average time (s) | Notes          |
|:------------: | :--------------: | :-------------:|
| C             | 0.825s           | gcc -O2        |
| C++           | 0.826s           | g++ -O2        |
| Cython        | 0.827s           | MSVC /O2       |
| Python        | 10.790s          | CPython 3.11.3 |

---

## Compiling and Running

You will need:

- C/C++ compiler ([MSVC](https://visualstudio.microsoft.com/downloads/) is recommended, or [MinGW](https://sourceforge.net/projects/mingw/))
- [Python 3.11](https://www.python.org/downloads/release/python-3119/)

### Recommended

- [Git](https://git-scm.com/downloads)
- Make (for Windows: <sup>[[1]](https://gnuwin32.sourceforge.net/packages/make.htm)[[2]](https://nerdyelectronics.com/install-mingw-on-windows-for-make/)</sup>)

Don't forget to set your [PATH](https://superuser.com/questions/284342/what-are-path-and-other-environment-variables-and-how-can-i-set-or-use-them) environment variables accordingly (if needed).

### Quick Setup

The quick setup you need to get up and running.

These commands will clone the project repository, install the required Python dependencies and build/run the project.

```shell
git clone https://github.com/Artprozew/BenchSyntaxLab.git
cd BenchSyntaxLab
python -m pip install -r requirements.txt
make
```

The `make` command defaults to build and run every language on the project. You can change this behavior by using `make <language/target>`. For example: `make python` would only run the Python code.

## Contributing

If you want to contribute to this project, please fork the repository and use a feature branch to make your changes on. When you are finished, you're welcome to open a pull request! 🤝

### Code Styling

This project generally follows these style guidelines:

- [PEP8](https://peps.python.org/pep-0008/)
- [Linux Kernel](https://www.kernel.org/doc/html/v4.10/process/coding-style.html)

However, we are currently flexible with minor details (e.g., tabs are still 4 spaces wide instead of 8).

## Licensing

This project is licensed under MIT license;
Refer to: [LICENSE](https://github.com/Artprozew/BenchSyntaxLab/blob/main/LICENSE)
