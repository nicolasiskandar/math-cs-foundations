% b
clc, clearvars, close all

x = [1 2 3 4 5];
y = [0.125 0.470 1.451 8.263 31.960];

u = ones(size(x))

figure;
plot(x, y, '*');
hold on;

% c
A = [x*x' x*u'; x*u' u*u']
r = [x*y' ; u*y']

z = A \ r
a = z(1)
b = z(2)

y_lin = a*x + b

err_lin = abs(y - y_lin)
max_err_lin = max(err_lin)

plot(x, y_lin, 'm--');

% d
Y = log(y)

A1 = [x*x' x*u'; x*u' u*u']
r1 = [x*Y' ; u*Y']

z1 = A1 \ r1
a1 = z1(1);
b1 = z1(2);

y_exp = exp(b1) * exp(a1*x);

err_exp = abs(y - y_exp);
max_err_exp = max(err_exp);

plot(x, y_exp, 'c-');

% e
legend('Data', 'Linear fit', 'Exponential fit');
xlabel('Year (x = year - 2000)');
ylabel('Sales (millions)');
title('iPod Sales Fit');

% f
% 2006 (x = 6)
y_2006 = exp(b1) * exp(a1*6)

% 2015 (x = 15)
y_2015 = exp(b1) * exp(a1*15)