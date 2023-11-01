# Отчёт по программам

## Численное интегрирование методами левых и средних прямоугольников и методом Симпсона

+ $f(x) = x, x \in [ 2, 7 ]$

    <table>
        <tr>
            <th rowspan="2" colspan="2"></th>
            <th colspan="5" style="text-align: center">Количество отрезков разбиения</th>
        </tr>
        <tr>
            <th>10</th>
            <th>20</th>
            <th>50</th>
            <th>100</th>
            <th>1000</th>
        </tr>
        <tr>
            <th rowspan="3" style="writing-mode: vertical-lr">Метод численного интегрирования</th>
            <th>Метод Симпсона</th>
            <td>22.5</td>
            <td>22.5</td>
            <td>22.5</td>
            <td>22.5</td>
            <td>22.5</td>
        </tr>
        <tr>
            <th>Метод левых прямоугольников</th>
            <td>21.25</td>
            <td>21.875</td>
            <td>22.25</td>
            <td>22.375</td>
            <td>22.4875</td>
        </tr>
        <tr>
            <th>Метод средних прямоугольников</th>
            <td>22.5</td>
            <td>22.5</td>
            <td>22.5</td>
            <td>22.5</td>
            <td>22.5</td>
        </tr>
    </table>

+ $f(x) = 0.7x^2, x \in [ -1, 0 ]$

    <table>
        <tr>
            <th rowspan="2" colspan="2"></th>
            <th colspan="5" style="text-align: center">Количество отрезков разбиения</th>
        </tr>
        <tr>
            <th>10</th>
            <th>20</th>
            <th>50</th>
            <th>100</th>
            <th>1000</th>
        </tr>
        <tr>
            <th rowspan="3" style="writing-mode: vertical-lr">Метод численного интегрирования</th>
            <th>Метод Симпсона</th>
            <td>0.233333</td>
            <td>0.233333</td>
            <td>0.233333</td>
            <td>0.233333</td>
            <td>0.233333</td>
        </tr>
        <tr>
            <th>Метод левых прямоугольников</th>
            <td>0.2695</td>
            <td>0.251125</td>
            <td>0.24038</td>
            <td>0.236845</td>
            <td>0.233683</td>
        </tr>
        <tr>
            <th>Метод средних прямоугольников</th>
            <td>0.23275</td>
            <td>0.233187</td>
            <td>0.23331</td>
            <td>0.233327</td>
            <td>0.233333</td>
        </tr>
    </table>

+ $f(x) = \sqrt{7x}, x \in [ 0, 3 ]$

    <table>
        <tr>
            <th rowspan="2" colspan="2"></th>
            <th colspan="5" style="text-align: center">Количество отрезков разбиения</th>
        </tr>
        <tr>
            <th>10</th>
            <th>20</th>
            <th>50</th>
            <th>100</th>
            <th>1000</th>
        </tr>
        <tr>
            <th rowspan="3" style="writing-mode: vertical-lr">Метод численного интегрирования</th>
            <th>Метод Симпсона</th>
            <td>9.152673</td>
            <td>9.160740</td>
            <td>9.164035</td>
            <td>9.164757</td>
            <td>9.165139</td>
        </tr>
        <tr>
            <th>Метод левых прямоугольников</th>
            <td>8.393116</td>
            <td>8.790937</td>
            <td>9.019820</td>
            <td>9.093612</td>
            <td>9.158188</td>
        </tr>
        <tr>
            <th>Метод средних прямоугольников</th>
            <td>9.188759</td>
            <td>9.173794</td>
            <td>9.167404</td>
            <td>9.165960</td>
            <td>9.165178</td>
        </tr>
    </table>

+ $f(x) = \ln(x + 2), x \in [ 0, 1 ] $

    <table>
        <tr>
            <th rowspan="2" colspan="2"></th>
            <th colspan="5" style="text-align: center">Количество отрезков разбиения</th>
        </tr>
        <tr>
            <th>10</th>
            <th>20</th>
            <th>50</th>
            <th>100</th>
            <th>1000</th>
        </tr>
        <tr>
            <th rowspan="3" style="writing-mode: vertical-lr">Метод численного интегрирования</th>
            <th>Метод Симпсона</th>
            <td>0.909542</td>
            <td>0.909543</td>
            <td>0.909543</td>
            <td>0.909543</td>
            <td>0.909543</td>
        </tr>
        <tr>
            <th>Метод левых прямоугольников</th>
            <td>0.889130</td>
            <td>0.899371</td>
            <td>0.905482</td>
            <td>0.907514</td>
            <td>0.909340</td>
        </tr>
        <tr>
            <th>Метод средних прямоугольников</th>
            <td>0.909612</td>
            <td>0.909560</td>
            <td>0.909545</td>
            <td>0.909543</td>
            <td>0.909543</td>
        </tr>
    </table>

+ $f(x) = x\sin(x), x \in [ -\pi, \pi ]$

    <table>
        <tr>
            <th rowspan="2" colspan="2"></th>
            <th colspan="5" style="text-align: center">Количество отрезков разбиения</th>
        </tr>
        <tr>
            <th>10</th>
            <th>20</th>
            <th>50</th>
            <th>100</th>
            <th>1000</th>
        </tr>
        <tr>
            <th rowspan="3" style="writing-mode: vertical-lr">Метод численного интегрирования</th>
            <th>Метод Симпсона</th>
            <td>6.283529</td>
            <td>6.283207</td>
            <td>6.283186</td>
            <td>6.283185</td>
            <td>6.283185</td>
        </tr>
        <tr>
            <th>Метод левых прямоугольников</th>
            <td>6.075104</td>
            <td>6.231423</td>
            <td>6.274915</td>
            <td>6.281118</td>
            <td>6.283165</td>
        </tr>
        <tr>
            <th>Метод средних прямоугольников</th>
            <td>6.387742</td>
            <td>6.309098</td>
            <td>6.287321</td>
            <td>6.284219</td>
            <td>6.283196</td>
        </tr>
    </table>

+ $f(x) = \frac{1}{1 + \exp(x)}, x \in [ -1, 0 ]$

    <table>
        <tr>
            <th rowspan="2" colspan="2"></th>
            <th colspan="5" style="text-align: center">Количество отрезков разбиения</th>
        </tr>
        <tr>
            <th>10</th>
            <th>20</th>
            <th>50</th>
            <th>100</th>
            <th>1000</th>
        </tr>
        <tr>
            <th rowspan="3" style="writing-mode: vertical-lr">Метод численного интегрирования</th>
            <th>Метод Симпсона</th>
            <td>0.620115</td>
            <td>0.620115</td>
            <td>0.620115</td>
            <td>0.620115</td>
            <td>0.620115</td>
        </tr>
        <tr>
            <th>Метод левых прямоугольников</th>
            <td>0.631623</td>
            <td>0.625880</td>
            <td>0.622423</td>
            <td>0.621269</td>
            <td>0.620230</td>
        </tr>
        <tr>
            <th>Метод средних прямоугольников</th>
            <td>0.620137</td>
            <td>0.620120</td>
            <td>0.620115</td>
            <td>0.620115</td>
            <td>0.620115</td>
        </tr>
    </table>

## Оценка точности вычисления определённого интеграла правилом Рунге

+ $f(x) = 2x^3 + 0.124, x \in [ 0, 2 ]$

    <table>
        <tr>
            <th rowspan="2" colspan="2"></th>
            <th colspan="4" style="text-align: center">Количество отрезков разбиения</th>
        </tr>
        <tr>
            <th>10</th>
            <th>20</th>
            <th>50</th>
            <th>100</th>
        </tr>
        <tr>
            <th rowspan="3" style="writing-mode: vertical-lr">Метод численного интегрирования</th>
            <th>Метод Симпсона</th>
            <td>nan</td>
            <td>nan</td>
            <td>nan</td>
            <td>nan</td>
        </tr>
        <tr>
            <th>Метод левых прямоугольников</th>
            <td>0.942667</td>
            <td>0.972166</td>
            <td>0.989057</td>
            <td>0.994559</td>
        </tr>
        <tr>
            <th>Метод средних прямоугольников</th>
            <td>2</td>
            <td>2</td>
            <td>2</td>
            <td>2</td>
        </tr>
    </table>

+ $f(x) = \cos(x), x \in \[ -\frac{\pi}{6}, \frac{\pi}{2} \]$

    <table>
        <tr>
            <th rowspan="2" colspan="2"></th>
            <th colspan="4" style="text-align: center">Количество отрезков разбиения</th>
        </tr>
        <tr>
            <th>10</th>
            <th>20</th>
            <th>50</th>
            <th>100</th>
        </tr>
        <tr>
            <th rowspan="3" style="writing-mode: vertical-lr">Метод численного интегрирования</th>
            <th>Метод Симпсона</th>
            <td>4.001484</td>
            <td>4.000371</td>
            <td>4.000059</td>
            <td>4.000059</td>
        </tr>
        <tr>
            <th>Метод левых прямоугольников</th>
            <td>0.000014</td>
            <td>0.966124</td>
            <td>0.986735</td>
            <td>0.993413</td>
        </tr>
        <tr>
            <th>Метод средних прямоугольников</th>
            <td>2.001731</td>
            <td>2.000433</td>
            <td>2.000069</td>
            <td>2.000017</td>
        </tr>
    </table>
