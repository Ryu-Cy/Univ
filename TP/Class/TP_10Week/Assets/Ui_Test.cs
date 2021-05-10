using System.Collections;
using System.Collections.Generic;
using UnityEngine;
//using UnityEngine.UI;
using TMPro;

public class Ui_Test : MonoBehaviour
{
    private GameObject target;
    public TextMeshProUGUI ScoreText;
    private int score;

    // Start is called before the first frame update
    void Start()
    {
        score = 0;
    }

    // Update is called once per frame
    void Update()
    {
        ScoreText.text = "Score: " + score.ToString();

        if (Input.GetMouseButtonDown(0))
        {
            score++;
        }
    }
}
