;; define out namespace
(ns hackerrank.arrayofNElements)

(defn solution [n]
  (format "[%s]" (clojure.string/join ", " (range 0 n))))

;; (fn [lst] (reduce + (map (fn [v] (if (odd? v) v 0)) lst)))
