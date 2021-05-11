using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class TextManager : MonoBehaviour
{
    public Text ScoreText;
    public Text TimeText;
    public Text LifeText;

    private float Timed;

    // Start is called before the first frame update
    void Start()
    {
        Timed = 0.0f;
    }

    // Update is called once per frame
    void Update()
    {
        Timed += Time.deltaTime;

        ScoreText.text = "Score: " + GameObject.Find("Player").GetComponent<Player>().Score;
        TimeText.text = "" + Mathf.Round(Timed);
        LifeText.text = "Life: " + GameObject.Find("Player").GetComponent<Player>().Life;
    }
}
