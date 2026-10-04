fn main() {
    // Дано натуральное число n. Выведите все числа от 1 до n.
    println!("Задание 1");
    print_1_to_n(5);
    /*
    Даны два целых числа A и В (каждое в отдельной строке).
    Выведите все числа от A до B включительно, в порядке возрастания, если A < B,
    или в порядке убывания в противном случае
    */
    println!("Задание 2");
    print_a_to_b(3, 6);
    print_a_to_b(7, 10);
    /*
    Дано натуральное число N. Вычислите сумму его цифр.
    При решении этой задачи нельзя использовать строки, списки, массивы (ну и циклы, разумеется).
    */
    println!("Задание 3");
    println!("{}", sum_of_digits(555));
    /*
    Дано натуральное число n>1. Выведите все простые делители этого числа в порядке возрастания.
    Алгоритм должен иметь сложность О(sqrt(n))
    */
    println!("Задание 4");
    let n = 222;
    print_simple_divisors(n, n.isqrt())
}

fn print_1_to_n(n: isize) {
    if n == 0 {
        return;
    }
    print_1_to_n(n - 1);
    println!("{n}");
}

fn print_a_to_b(a: usize, b: usize) {
    if a == b {
        println!("{b}");
        return;
    }
    if a <= b {
        println!("{a}");
        print_a_to_b(a + 1, b);
    } else {
        println!("{a}");
        print_a_to_b(a - 1, b);
    }
}

fn sum_of_digits(n: usize) -> usize {
    if n < 10 {
        return n;
    }
    let power = (n as f64).log10().floor();
    let power10 = 10usize.pow(power as u32);
    let left_digit = n / power10;
    left_digit + sum_of_digits(n - left_digit * power10)
}

fn print_simple_divisors(n: usize, current: usize) {
    if current == 0 {
        return;
    }
    print_simple_divisors(n, current - 1);
    if n % current == 0 {
        println!("{current}");
    }
}
