(ns bird-watcher)

(def last-week [0 2 5 3 7 8 4])

(defn today [birds]
  (last birds))

(defn inc-bird [birds]
  (conj (vec (drop-last birds)) (inc (today birds))))

(defn day-without-birds? [birds]
  (if (= (some zero? birds) nil) false true))

(defn n-days-count [birds n]
  (->> [0 birds]
       (iterate (fn [[sum xs]] [(+ sum (first xs)) (rest xs)]))
       (map first)
       (take (inc n))
       (last)))

(defn busy-days [birds]
  (count (filter #(>= % 5) birds)))

(defn odd-week? [birds]
  (empty? (remove #(= '(1 0) %) (partition 2 birds))))
