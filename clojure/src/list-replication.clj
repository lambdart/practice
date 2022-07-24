;; define out namespace
(ns hackerrank.listReplication)

(defn solution [n lst]
  (vec (mapcat (fn [v] (repeat n v)) lst)))
