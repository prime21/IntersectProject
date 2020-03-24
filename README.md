# README
17373260 彭毛小民

17373015 乔玺华

## how-to-use

dir `bin` has a core CLI application
dir `guibin` has a GUI application with our dll file
dir `guiwithotherdll` has a GUI application with dll file from other group.

## preliminary

1. 两条直线的交点公式，联立

$$
A_1 x + B_1 y + C_1 = 0 \\
A_2 x + B_2 y + C_2 = 0
$$

解得 
$$
X = \frac{B_1 C_2 - B_2 C_1} {A_1 B_2 - A_2 B_1} \\
Y = \frac{B_1 C_2 - B_2 C_1} {A_1 B_2 - A_2 B_1}
$$

2. 两个圆的交点公式$C_1(O_1,r_1),C_2(O_2,r_2)$

   不相交的情况$$ |O_1O_2| < |r_1-r_2|$$ 或者 $|O_1O_2| > r_1+r_2$

   其余情况，考察连心线和交点弦的垂直关系，先求交点弦和连心线的交点$P$

   $P = O_1 + \overrightarrow {i_{O_1O_2}} \times a$

   其中$a = \frac {r_1^2 - r_2^2 + d^2} {2d} $

   然后在垂直方向上得到交点$P' = P \pm \overrightarrow j \times h$

   $\overrightarrow j$是$\overrightarrow i$的法向量，$h = \sqrt{r_1^2 - a^2}$
   
3. 直线和圆的交点公式，考虑直线为向量式$u = u_0 + t (u_1-u_0)$，圆为$C(O,r)$

   由$|uO| = r$消去得$|u_0 + t (u_1-u_0) - O| = r$ 为关于$t$的一个二次方程，解得两个$t$，得交点

4. sweep-line

观察一下直线相交的性质

观察一下圆和圆相交的性质

观察一下圆和直线相交的性质
