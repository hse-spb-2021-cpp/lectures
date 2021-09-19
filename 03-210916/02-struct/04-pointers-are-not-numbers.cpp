// Not for exam!

// Consider the following code:
int a[...], b[...];

...
    a[i] = 10;
    b[j] = 20;
    int x = a[i];  // We would like to optimize it to x = 10
...

// And here be dragons: https://www.ralfj.de/blog/2020/12/14/provenance.html
