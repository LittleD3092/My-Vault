function q = par_pass(t, p, flag, m, n)
    x1 = p(1); x2 = p(2);

    u = 1;

    q = zeros(2, 1);
    q(1) = x2;
    q(2) = -n*x1-m*x2 + u;