package com.tdusnewbie.root.random_androidtutorial;

import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.TextView;

import java.util.Random;

public class MainActivity extends AppCompatActivity {


    Button button;
    TextView textView;
    ProgressBar progressBar;
    EditText editText;
    int inputNum;
    double ratio, result = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Reference();

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                progressBar.setProgress(0);
                inputNum = Integer.valueOf(editText.getText().toString());
                ratio = progressBar.getMax() / inputNum;
                button.setEnabled(false);
                new Percent().execute();
            }
        });

    }

    private class Percent extends AsyncTask<Void,Integer,Integer>
    {

        @Override
        protected void onProgressUpdate(Integer... values) {
            super.onProgressUpdate(values);
            textView.setText(values[0] + "%");
            progressBar.setProgress(values[0]);
        }

        @Override
        protected Integer doInBackground(Void... voids) {
            int temp = inputNum / progressBar.getMax();
            while(progressBar.getProgress() < 100)
            {
                for(int i = 0; i <= temp; i ++) {
                    if (i == temp) {
                        publishProgress(progressBar.getProgress() + 1);
                        Log.d("Background", "Đang tăng đơn vị lên");
                    }
                }
                progressBar.setProgress(progressBar.getProgress() + 1);
            }
            return 100;
        }

        @Override
        protected void onPostExecute(Integer integer) {
            super.onPostExecute(integer);
            button.setEnabled(true);
            textView.setText(integer + "%");
            Log.d("Background","Kêts thúc background");
        }
    }

    private void Reference()
    {
        button = (Button) findViewById(R.id.button);
        textView = (TextView) findViewById(R.id.textView);
        progressBar = (ProgressBar) findViewById(R.id.progressBar);
        editText = (EditText) findViewById(R.id.editText);
    }
}
