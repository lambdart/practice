(ns lab
  (:require [clojure.string :as str]))

(def i (atom 0)) ;; counter/index
(def ans (atom 0.0)) ;; answer: accumulator

(defn read-value []
  (map #(Integer/parseInt %) (-> (read-line) (str/split #" "))))

(defn calc-dist [x y]
  (let [a (first x) b (-> x rest first)
        c (first y) d (-> y rest first)]
    (Math/sqrt (+ (Math/pow (- c a) 2)
                  (Math/pow (- d b) 2)))))

(defn solution []
  (let [n (first (read-value))
        limit (- N 1)
        ps (repeatedly N #(read-value))
        p1 (first ps)
        pn (last ps)]
    (while (< @i limit)
      (swap! ans #(+ % (calc-dist (nth ps @i)
                                  (nth ps (inc @i)))))
      (swap! i inc))
    (+ @ans (calc-dist p1 pn))))

(println (solution))
