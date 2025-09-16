(ns all-your-base)

(defn not-base? [base]
  (or (= base 1)
      (< base 0)
      (= base 0)))

(defn not-number? [number]
  (not (number? number)))

(defn not-digit? [digit base]
  (or (>= digit base) (< digit 0)))

(defn toDigits [number base]
  (cond
    (not-base? base) nil
    (not-number? number) nil
    (zero? number) '(0)
    :else
    (loop [number number
           digits '()]
      (if (<= number 0)
        digits
        (recur
         (quot number base)
         (conj digits (rem number base)))))))

(defn fromDigits [digits base]
  (cond (empty? digits) nil
        (not-base? base) nil
        :else
        (loop [digits digits
               number 0]
          (if (empty? digits)
            number
            (let [digit (first digits)]
              (if (not-digit? digit base)
                nil
                (recur (rest digits)
                       (+ (* base number) digit))))))))

(defn convert [base digits target] ;; <- arglist goes here
  (toDigits (fromDigits digits base) target))
