(ns lab
  (:require [clojure.string :as str]))

(defn read-values []
  (map #(Long/parseLong %)
       (-> (read-line) (str/split #" "))))

(defn func [c p x]
  (let [cp (zipmap c p)]
    (reduce-kv (fn [r i e]
                 (->> e (Math/pow x) (* i) (+ r)))
               0 cp)))

;; return the Riemann's right sum (integral approximation)
(defn riemann-right-sum
  "Definite integration of f over [a, b] using Riemman's right sum."
  [f L R dx]
  (reduce + (map #(f %) (range L (+ R dx) dx))))

;; calculates the area besides the curve
(defn calc-area [f L R dx]
  (* dx (riemann-right-sum f L R dx)))

(defn calc-volume [f L R dx]
  (* Math/PI (riemann-right-sum f L R dx)))

(defn solution [dx]
  (let [a (read-values)
        b (read-values)
        [L R] (read-values)
        ;; calculates the area
        A (calc-area (fn [x] (func a b x)) L R dx)
        ;; calculates the volume
        V (calc-volume (fn [x] (-> (func a b x)
                                   (Math/pow 2)
                                   (* dx)))
                       L R dx)]
    (println A)
    (println V)))

(solution 0.001)
