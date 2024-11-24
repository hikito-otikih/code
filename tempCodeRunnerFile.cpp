for (int i = 1; i <= m; i ++)
    {
        int k = i ^ x;
        if (k % i == 0 || k % x == 0) 
        {
            cout << i << ' ' << k << '\n';
        }
    }