(ns lab
  (:require [clojure.string :as str]))

(defn read-value []
  (map #(Integer/parseInt %) (-> (read-line) (str/split #" "))))

(defn calc-dist [x y]
  (let [a (first x) b (-> x rest first)
        c (first y) d (-> y rest first)]
    (Math/sqrt (+ (Math/pow (- c a) 2)
                  (Math/pow (- d b) 2)))))

(def i (atom 0))
(def ans (atom 0.0))

(defn solution []
  (let [N (first (read-value))
        POINTS (repeatedly N #(read-value))
        LIMIT (- N 1)
        FIRST (first POINTS)
        LAST  (last POINTS)]
    (while (< @i LIMIT)
      (swap! ans #(+ % (calc-dist (nth POINTS @i)
                                  (nth POINTS (inc @i)))))
      (swap! i inc))
    (println (+ @ans (calc-dist FIRST LAST)))))

(solution)

