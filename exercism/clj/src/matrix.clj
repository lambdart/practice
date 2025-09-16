(ns matrix
  (:require [clojure.string :as str]))

(defn parse-int [s]
  (Integer. (re-find #"[0-9]*" s)))

(defn str2matrix [s]
  (->>
   s
   (str/split-lines)
   (mapv #(mapv parse-int (str/split % #" ")))))

(defn get-row
  "Returns the i-th row of the matrix s"
  [s i]
  (-> s
      str2matrix
      (#(get % (- i 1)))))

(defn get-column
  "Returns the i-th column of the matrix s"
  [s i]
  (-> s
      str2matrix
      (#(map (fn [row] (get row (- i 1))) %))))


