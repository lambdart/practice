(ns raindrops)

(defn divisible?
  [num div msg]
  (if (zero? (rem num div)) msg ""))

(defn convert
  "Converts a number to its corresponding string of raindrop sounds."
  [num]
  ((fn [x] (apply str (if-not (empty? x) x `(~num))))
   (mapcat (fn [[x y]]
             (divisible? num
                         x
                         y))
           '((3 "Pling")
             (5 "Plang")
             (7 "Plong")))))

;; (convert 12)

;; (loop [ans ""
;;        divs '(3 5 7)
;;        msgs '("Pling" "Plang" "Plong")]
;;   (if (empty? divs)
;;     (if (empty? ans)
;;       (str num)
;;       ans)
;;     (recur (str ans (divisible? num (first divs) (first msgs)))
;;            (rest divs)
;;            (rest msgs)))))


;; (let [ans (apply str `(""
;;                        ~(if (zero? (rem num 3)) "Pling" "")
;;                        ~(if (zero? (rem num 5)) "Plang" "")
;;                        ~(if (zero? (rem num 7)) "Plong" "")))]
;;   (if (empty? ans)
;;     (str num)
;;     ans)))
