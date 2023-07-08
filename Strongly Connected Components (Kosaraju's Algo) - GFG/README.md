# Strongly Connected Components (Kosaraju's Algo)
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a Directed Graph with<strong> V </strong>vertices <strong>(</strong>Numbered from<strong> 0 to V-1)</strong>&nbsp;and <strong>E</strong> edges</span>, <span style="font-size: 18px;">Find </span><span style="font-size: 18px;">the number of strongly connected components in the graph.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700394/Web/Other/89b7c4e7-e03c-402f-b445-3e8815299af6_1685086635.png" alt="">
<span style="font-size: 18px;"><strong>Output:</strong>
3
<strong>Explanation</strong>:
</span><img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700394/Web/Other/9f4ccc7f-8ad8-4f81-908a-01f27090ba5e_1685086635.png" alt="">
<span style="font-size: 18px;">We can clearly see that there are 3 Strongly
Connected Components in the Graph</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700394/Web/Other/8b9b3908-a800-4ffa-acaf-26cb760eac8e_1685086635.png" alt="">
<span style="font-size: 18px;"><strong>Output:</strong>
1
<strong>Explanation</strong>:</span>
<span style="font-size: 18px;">All of the nodes are connected to each other.
So, there's only one SCC.</span>
</pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>kosaraju()</strong> which takes the number of vertices V and adjacency list of the graph of size V as inputs and returns an integer denoting the number of strongly connected components in the given graph.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(V+E).<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(V+E).</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> V </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> 5000<br>0 </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> E </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> (V*(V-1))<br>0 </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> u, v </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> V-1<br>Sum of E over all testcases will not exceed 25*10<sup>6</sup></span></p></div>