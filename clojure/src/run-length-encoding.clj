(ns solution.run-length-encoding
  (:require [clojure.string :as str :refer [join blank?]]
            [criterium.core :refer [quick-bench with-progress-reporting]]))

(defn run-length-encode [s]
  (apply str
         (remove #{1}
                 (mapcat (juxt count first)
                         (partition-by identity s)))))

(defn run-length-decode
  [s]
  (apply str
         (mapcat (fn [[_ n c]]
                   (repeat (if (= n "") 1 (Integer. n)) c))
                 (re-seq #"(\d*)(\D)" s))))
