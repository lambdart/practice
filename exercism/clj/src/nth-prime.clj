(ns nth-prime)

(defn prime?
  "Trivial solution test all the `primes` divisions prior the
  square root of `number`."
  [primes number]
  (loop [ps primes] ; local copy
    (let [d (first ps)
          n number]
      (cond
        (= (mod n d) 0) false
        (> d (Math/sqrt n)) true
        :else (recur (rest ps))))))

(defn gen-primes
  "Recursive function that will return a list of `n` primes."
  [n]
  (loop [total  1
         number 3
         primes [2]]
    (if (< total n)
      (let [temp (prime? primes number)]
        (recur (+ total (if temp 1 0))
               (+ number 2)
               (if temp (conj primes number) primes)))
      primes)))

(defn nth-prime
  "Returns the prime number in the nth position."
  [n]
  (case n
    0 (throw (IllegalArgumentException. ""))
    (peek (gen-primes n))))

(defn sieve-of-eratosthenes [n]
  (let [arr (vec (repeat n 0))]
    (loop [j 3
           `ps arr]
      (if (> j n)
        ps
        (recur (+ j 2)
               (loop [i 3
                      ts ps]
                 (if (> (* i j) n)
                   ts
                   (recur (+ i 2) (assoc ts (* i j) 1)))))))))
